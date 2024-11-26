#include "func_getattr_newest.hpp"

#include "fs_lstat.hpp"
#include "fs_inode.hpp"
#include "timespec_utils.hpp"

int
Func2::GetattrNewest::process(const Branches  &branches_,
                              const fs::Path  &fusepath_,
                              struct stat     *st_,
                              fuse_timeouts_t *timeout_)
{
  int rv;
  Branch *newest_branch;
  Branches::CPtr branches;
  fs::Path fullpath;

  branches = branches_;
  newest_branch = nullptr;

  for(const auto &branch : *branches)
    {
      struct stat tmp_st;

      fullpath = branch.path;
      fullpath += fusepath_;
      rv = fs::lstat(fullpath.c_str(),&tmp_st);
      if(rv == -1)
        continue;

      if(!TimeSpec::is_newer(tmp_st.st_mtim,st_->st_mtim))
        continue;

      *st_ = tmp_st;
      newest_branch = &branch;
    }

  if(st_->st_ino == 0)
    return -ENOENT;

  fs::inode::calc(fusepath_,st_);

  return 0;
}
