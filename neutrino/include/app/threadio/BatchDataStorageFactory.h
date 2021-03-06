
#ifndef __NEUTRINO_IMPLEMENT_THREADIO_BATCHDATASTORAGEFACTORY_H
#define __NEUTRINO_IMPLEMENT_THREADIO_BATCHDATASTORAGEFACTORY_H

#include <iostream>
#include <map>
#include "BatchDataStorage.h"
#include "neutrino_implement/core/base/neutrino_logger.h"
#include "neutrino_implement/core/base/neut.h"

namespace neutrino_implement {
  class ThreadProcessor;
  /**
     \class BatchDataStorageFactory
     User defined class BatchDataStorageFactory ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class BatchDataStorageFactory {
    friend ThreadProcessor;
  public:

    BatchDataStorageFactory()
    {}

    ~BatchDataStorageFactory()
    {}
    /*
    inline static const BatchDataStorageFactory<T>& get() {
      if (!_me) _me = new BatchDataStorageFactory<T>();
      return (*_me);
    }
    */
    static const BatchDataStorageFactory<T>& get();

    inline bool exist_storage(std::string name) const
    {
      auto iter = _storage_m.find(name);
      return iter != _storage_m.end();
    }

    const BatchDataStorage<T>& get_storage(std::string name) const;
    /*
    inline const BatchDataStorage<T>& get_storage(std::string name) const
    {
      if (!_me) _me = new BatchDataStorageFactory<T>();
      auto iter = _storage_m.find(name);
      if (iter == _storage_m.end()) {
        NEUTRINO_SCRITICAL() << "BatchDataStorage w/ name " << name << " not found!" << std::endl;
        throw neut();
      }
      return iter->second;
    }
    */
    inline bool make_storage(std::string name, size_t num_batch = 1)
    {
      if (exist_storage(name)) {
        NEUTRINO_SERROR() << "Storage name " << name << " already present..." << std::endl;
        return false;
      }
      _storage_m.emplace(std::make_pair(name, num_batch));
      return true;
    }

    BatchDataStorage<T>& get_storage_writeable(std::string name);
    /*
    inline BatchDataStorage<T>& get_storage_writeable(std::string name) {
      if (!_me) _me = new BatchDataStorageFactory<T>();
      auto iter = _storage_m.find(name);
      if (iter == _storage_m.end()) {
        NEUTRINO_SCRITICAL() << "BatchDataStorage w/ name " << name << " not found!" << std::endl;
        throw neut();
      }
      return iter->second;
    }
    */
  private:
    static BatchDataStorageFactory<T>& get_writeable();
    /*
    inline static BatchDataStorageFactory<T>& get_writeable() {
      if (!_me) _me = new BatchDataStorageFactory<T>();
      return (*_me);
    }
    */
  private:
    static BatchDataStorageFactory<T>* _me;
    std::map<std::string, BatchDataStorage<T> > _storage_m;
  };

}

#endif
/** @} */ // end of doxygen group
