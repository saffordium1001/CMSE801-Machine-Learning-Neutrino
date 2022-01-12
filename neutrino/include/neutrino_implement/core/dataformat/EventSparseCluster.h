
#ifndef __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTSPARSECLUSTER_H
#define __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTSPARSECLUSTER_H

#include <iostream>
#include "neutrino_implement/core/dataformat/EventBase.h"
#include "neutrino_implement/core/dataformat/DataProductFactory.h"
#include "neutrino_implement/core/dataformat/Voxel.h"
#include "neutrino_implement/core/dataformat/ImageMeta.h"

namespace neutrino_implement {

  /**
    \class EventSparseCluster2D
    \brief Event-wise class to store a collection of VoxelSet (cluster) per projection id
  */
  template<size_t dimension>
  class EventSparseCluster : public EventBase {

  public:

    /// Default constructor
    EventSparseCluster();

    /// Default destructor
    virtual ~EventSparseCluster() {}

    /// EventBase::clear() override
    inline void clear() {_cluster_v.clear();}

    /// Access to all stores neutrino_implement::SparseCluster
    inline const std::vector<neutrino_implement::SparseCluster<dimension> >& as_vector() const { return _cluster_v; }

    /// Access SparseCluster of a specific projection ID
    const neutrino_implement::SparseCluster<dimension> & sparse_cluster(const ProjectionID_t id) const;

    /// Number of valid projection id
    inline size_t size() const { return _cluster_v.size(); }

    //
    // Write-access
    //
    /// Emplace data
    void emplace(neutrino_implement::SparseCluster<dimension>&& clusters);
    /// Set data
    void set(const neutrino_implement::SparseCluster<dimension>& clusters);
    /// Emplace a new element
    void emplace(neutrino_implement::VoxelSetArray&& clusters, neutrino_implement::ImageMeta<dimension>&& meta);
    // /// Set a new element
    // void set(const neutrino_implement::VoxelSetArray& clusters, const neutrino_implement::ImageMeta& meta);



    // IO functions:
    void initialize (hid_t group, uint compression);
    void serialize  (hid_t group);
    void deserialize(hid_t group, size_t entry, bool reopen_groups=false);
    void finalize   ();


    static EventSparseCluster * to_sparse_cluster(EventBase * e){
      return (EventSparseCluster *) e;
    }

  private:
    void open_in_datasets(hid_t group);
    void open_out_datasets(hid_t group);
    std::vector<neutrino_implement::SparseCluster<dimension> > _cluster_v;

  };

typedef EventSparseCluster<2> EventSparseCluster2D;
typedef EventSparseCluster<3> EventSparseCluster3D;

}


#include "IOManager.h"
namespace neutrino_implement {

  // Template instantiation for IO
  template<> inline std::string product_unique_name<neutrino_implement::EventSparseCluster2D>() { return "cluster2d"; }
  template<> inline std::string product_unique_name<neutrino_implement::EventSparseCluster3D>() { return "cluster3d"; }


  //    \class neutrino_implement::EventSparseCluster
  //    \brief A concrete factory class for neutrino_implement::EventSparseCluster


  class EventSparseCluster2DFactory : public DataProductFactoryBase {
  public:
    /// ctor
    EventSparseCluster2DFactory()
    { DataProductFactory::get().add_factory(product_unique_name<neutrino_implement::EventSparseCluster2D>(), this); }
    /// dtor
    ~EventSparseCluster2DFactory() {}
    /// create method
    EventBase* create() { return new EventSparseCluster2D; }
  };

  class EventSparseCluster3DFactory : public DataProductFactoryBase {
  public:
    /// ctor
    EventSparseCluster3DFactory()
    { DataProductFactory::get().add_factory(product_unique_name<neutrino_implement::EventSparseCluster3D>(), this); }
    /// dtor
    ~EventSparseCluster3DFactory() {}
    /// create method
    EventBase* create() { return new EventSparseCluster3D; }
  };

}

#endif
/** @} */ // end of doxygen group
