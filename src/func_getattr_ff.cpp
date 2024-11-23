#include "func_getattr_ff.hpp"

int
Func2::GetattrFF::process(const Branches  &branches_,
                          const fs::Path  &fusepath_,
                          struct stat     *st_,
                          fuse_timeouts_t *timeout_)
{
  Branches::CPtr branches;
  fs::Path fullpath;

  branches = branches_;
  
  for(const auto &branch : *branches)
    {
      fullpath = branch.path;
      fullpath /= fusepath_;
    }

  return 0;
}
