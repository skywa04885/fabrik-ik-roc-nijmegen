#include "luke-fabrik/FABRIK.hpp"

double FABRIK_Forward (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target)
{
    Vec3 from (0., 0., 0.);
    for (std::vector <std::shared_ptr<Joint>>::iterator it = start; it != end; ++it)
    {
        Joint &joint = *(*it);

        joint.FABRIK_ForwardUpdate (from);
        from = joint.GetB ();
    }

    // Returns the distance to the target.
    return (*(*(end - 1UL))).GetB ().DistanceTo (target);
}

void FABRIK_Backward (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target)
{
    Vec3 from = target;

    std::vector <std::shared_ptr<Joint>>::iterator it = end;
    while (it != start)
    {
        --it;

        Joint &joint = *(*it);

        joint.FABRIK_BackwardUpdate (from);
        from = joint.GetA ();
    }
}

FABRIK_RetType FABRIK (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target, const FABRIK_Config &config)
{
    unsigned int i;
    double error;

    // Stays in loop until we've reached the desired tolerance or if
    //  we ran out of loops.
    for (i = 0; i < config.iterations; ++i)
    {
        // Performs the backward phase.
        FABRIK_Backward (start, end, target);

        // Performs the forward phase and stores the error.
        error = FABRIK_Forward (start, end, target);

        // Checks if we enabled verbose mode.
        if (config.verbose)
        {
            std::cout << "[Verbose FABRIK] -> iteration " << i << ", Forward Phase Error: "
                <<  error << std::endl;
        }
        
        // Checks if we've reached the desired error.
        if (error < config.tolerance)
        {
            break;
        }
    }

    if (config.verbose)
    {
        std::cout << "[Verbose FABRIK] -> Done solving, had " << i << " iterations, Reached Error: "
            <<  error << std::endl;
    }

    return FABRIK_RetType (error, i);
}
