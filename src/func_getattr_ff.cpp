#include "func_getattr_ff.hpp"

int
Func2::process(const Branches  &branches_,
               const fs::Path  &fusepath_,
               struct stat     *st_,
               fuse_timeouts_t *timeout_)
{
  return -ENOENT;
}
