

#ifndef __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTSPARSETENSOR_H
#define __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTSPARSETENSOR_H


#include <iostream>
#include "neutrino_implement/core/dataformat/EventBase.h"
#include "neutrino_implement/core/dataformat/DataProductFactory.h"
#include "neutrino_implement/core/dataformat/Voxel.h"
#include "neutrino_implement/core/dataformat/ImageMeta.h"



namespace neutrino_implement {

  /**
    \class EventSparseTensor
    \brief Event-wise class to store a collection of VoxelSet (cluster) per projection id
  */
  template<size_t dimension>
  class EventSparseTensor : public EventBase {

  public:

    /// Default constructor
    EventSparseTensor();


    //
    // Read-access
    //
    /// Access to all stores neutrino_implement::SparseTensor
    inline const std::vector<neutrino_implement::SparseTensor<dimension> >& as_vector() const { return _tensor_v; }
    /// Access SparseTensor<dimension>  of a specific projection ID
    const neutrino_implement::SparseTensor<dimension> & sparse_tensor(const ProjectionID_t id) const;
    /// Number of valid projection id
    inline size_t size() const { return _tensor_v.size(); }

    //
    // Write-access
    //
    /// EventBase::clear() override
    void clear() {}
    /// Emplace data
    void emplace(neutrino_implement::SparseTensor<dimension> && voxels);
    /// Set data`
    void set(const neutrino_implement::SparseTensor<dimension> & voxels);
    /// Emplace a new element
    void emplace(neutrino_implement::VoxelSet&& voxels, neutrino_implement::ImageMeta<dimension>&& meta);
    /// Set a new element
    void set(const neutrino_implement::VoxelSet& voxels, const neutrino_implement::ImageMeta<dimension>& meta);


    // IO functions:
    void initialize (hid_t group, uint compression);
    void serialize  (hid_t group);
    void deserialize(hid_t group, size_t entry, bool reopen_groups=false);
    void finalize   ();

    static EventSparseTensor * to_sparse_tensor(EventBase * e){
      return (EventSparseTensor *) e;
    }

  private:
    void open_in_datasets(hid_t group);
    void open_out_datasets(hid_t group);

    std::vector<neutrino_implement::SparseTensor<dimension> >  _tensor_v;



  };


typedef EventSparseTensor<2>  EventSparseTensor2D;
typedef EventSparseTensor<3>  EventSparseTensor3D;


}


#include "IOManager.h"
namespace neutrino_implement {

  // Template instantiation for IO
  template<> inline std::string product_unique_name<neutrino_implement::EventSparseTensor2D>() { return "sparse2d"; }
  template<> inline std::string product_unique_name<neutrino_implement::EventSparseTensor3D>() { return "sparse3d"; }


  /**
     \class neutrino_implement::EventSparseTensorFactory
     \brief A concrete factory class for neutrino_implement::EventSparseTensor
  */


  template<size_t dimension>
  class EventSparseTensorFactory : public DataProductFactoryBase {
  public:
    /// ctor
    EventSparseTensorFactory()
    { DataProductFactory::get().add_factory(product_unique_name<neutrino_implement::EventSparseTensor<dimension>>(), this); }
    /// dtor
    ~EventSparseTensorFactory() {}
    /// create method
    EventBase* create() { return new EventSparseTensor<dimension>; }
  };

}

#endif
/** @} */ // end of doxygen group
