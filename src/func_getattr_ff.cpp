#include "func_getattr_ff.hpp"

#include "fs_lstat.hpp"

int
Func2::GetattrFF::process(const Branches  &branches_,
                          const fs::Path  &fusepath_,
                          struct stat     *st_,
                          fuse_timeouts_t *timeout_)
{
  int rv;
  Branches::CPtr branches;
  fs::Path fullpath;

  branches = branches_;
  
  for(const auto &branch : *branches)
    {
      fullpath = branch.path;
      fullpath /= fusepath_;
      rv = fs::lstat(fullpath.c_str(),st_);
      printf("%s %d\n",fullpath.c_str(),rv);
      if(rv == 0)
        return 0;
    }

  return -ENOENT;
}
