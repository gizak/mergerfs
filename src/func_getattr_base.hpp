#pragma once

namespace Func2
{
  class GetattrBase
  {
  public:
    GetattrBase() {}
    ~GetattrBase() {}
  public:
    virtual int process(const Branches &branches,
                        const fs::Path &fusepath,
                        const mode_t mode,
                        fuse_file_info_t *ffi) = 0;
  };
}
