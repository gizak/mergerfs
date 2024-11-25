#pragma once

namespace TimeSpec
{
  static
  inline
  timespec
  newest(const timespec &t0_,
         const timespec &t1_)
  {
    if(t0_.tv_sec > t1_.tv_sec)
      return t0_;
    if(t0_.tv_sec == t1_.tv_sec)
      {
        if(t0_.tv_nsec > t1_.tv_nsec)
          return t0_;
      }

    return t1_;
  }
}
