#include "func_getattr_ff.hpp"

int
Func2::GetattrFF::process(const Branches  &branches_,
                          const fs::Path  &fusepath_,
                          struct stat     *st_,
                          fuse_timeouts_t *timeout_)
{
  for(const auto &branch : branches_)
    {
      
    }

  return 0;
}
