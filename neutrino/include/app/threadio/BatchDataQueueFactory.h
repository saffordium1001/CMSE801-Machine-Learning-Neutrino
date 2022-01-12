
#ifndef __NEUTRINO_IMPLEMENT_THREADIO_BATCHDATAQUEUEFACTORY_H
#define __NEUTRINO_IMPLEMENT_THREADIO_BATCHDATAQUEUEFACTORY_H

#include <iostream>
#include <map>
#include "BatchDataQueue.h"
#include "neutrino_implement/core/base/neutrino_logger.h"
#include "neutrino_implement/core/base/neut.h"

namespace neutrino_implement {
  class QueueProcessor;
  /**
     \class BatchDataQueueFactory
     User defined class BatchDataQueueFactory ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class BatchDataQueueFactory {
    friend QueueProcessor;
  public:

    BatchDataQueueFactory()
    {}

    ~BatchDataQueueFactory()
    {}

    static const BatchDataQueueFactory<T>& get();

    inline bool exist_queue(std::string name) const
    {
      auto iter = _queue_m.find(name);
      return iter != _queue_m.end();
    }

    bool is_next_ready() const;

    // Pop all queues to promote next to current
    void pop_all();

    const BatchDataQueue<T>& get_queue(std::string name) const;

    inline bool make_queue(std::string name)
    {
      if (exist_queue(name)) {
        NEUTRINO_SERROR() << "Queue name " << name << " already present..." << std::endl;
        return false;
      }
      _queue_m.emplace(std::make_pair(name, BatchDataQueue<T>()));
      return true;
    }

    BatchDataQueue<T>& get_queue_writeable(std::string name);

  private:
    static BatchDataQueueFactory<T>& get_writeable();

  private:
    static BatchDataQueueFactory<T>* _me;
    std::map<std::string, BatchDataQueue<T> > _queue_m;
  };

}

#endif
/** @} */ // end of doxygen group
