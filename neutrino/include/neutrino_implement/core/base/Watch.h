#ifndef __NEUTRINO_IMPLEMENT__BASE_WATCH_H__
#define __NEUTRINO_IMPLEMENT__BASE_WATCH_H__


#include <sys/time.h>
#include <time.h>

namespace neutrino_implement {

  /**
     \class neutrino_implement::Watch
     @brief a _very_ simple stopwatch class for simple time measurement
   */
  class Watch {
  public:
    Watch(){}
    ~Watch(){}

    /// Start stop watch
    void Start() {
      // Get current wall time
      struct timeval current_time;
      gettimeofday(&current_time,NULL);
      _wall_time_start = (double)current_time.tv_sec + (double)current_time.tv_usec * 1.e-6;
      // Get current cpu time
      _cpu_time_start = (double)(clock());
    }
    /// Report wall-clock time [s] since Start() call
    double WallTime() {
      // Get current wall time
      struct timeval current_time;
      gettimeofday(&current_time,NULL);
      double now = (double)current_time.tv_sec + (double)current_time.tv_usec * 1.e-6;
      // Return diff
      return (now - _wall_time_start);
    }
    /// Report cpu-clock time [s] since Start() call
    double CPUTime() {
      // Get cpu time
      double now = (double)(clock());
      // Return diff
      return (now - _cpu_time_start)/CLOCKS_PER_SEC;
    }
  private:
    double _cpu_time_start;
    double _wall_time_start;
  };
}
#endif
/** @} */ // end of doxygen group
