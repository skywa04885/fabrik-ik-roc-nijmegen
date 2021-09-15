#pragma once

#include <memory>
#include <vector>

#include "luke-fabrik/Joint.hpp"

class Skeleton
{
protected:
    std::size_t m_NextID;
    std::vector <std::shared_ptr <Joint>> m_Heads;
    std::shared_ptr <Joint> m_Root;
};
