
#ifndef __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTPARTICLE_H
#define __NEUTRINO_IMPLEMENT_DATAFORMAT_EVENTPARTICLE_H

#include "neutrino_implement/core/dataformat/EventBase.h"
#include "neutrino_implement/core/dataformat/Particle.h"
#include "neutrino_implement/core/dataformat/DataProductFactory.h"

class EventParticle;

namespace neutrino_implement {
  /**
    \class EventParticle
    User-defined data product class (please comment!)
  */
  class EventParticle : public EventBase {

  public:

    /// Default constructor
    EventParticle();

    /// Default destructor
    ~EventParticle(){}




    void set(const std::vector<neutrino_implement::Particle>& part_v);
    void append(const neutrino_implement::Particle& part);
    void emplace_back(neutrino_implement::Particle&& part);
    void emplace(std::vector<neutrino_implement::Particle>&& part_v);

    inline const std::vector<neutrino_implement::Particle>& as_vector() const
    { return _part_v; }

    inline size_t size() const {return _part_v.size();}

// #ifndef SWIG
    /// Data clear method
    void clear      ();
    void initialize (hid_t group, uint compression);
    void serialize  (hid_t group);
    void deserialize(hid_t group, size_t entry, bool reopen_groups=false);
    void finalize   ();
// #endif

    static EventParticle * to_particle(EventBase * e){
      return (EventParticle *) e;
    }

  private:

    void open_in_datasets(hid_t group);
    void open_out_datasets(hid_t group);

    std::vector<neutrino_implement::Particle> _part_v; ///< a collection of particles (index maintained)

  };
}


#include "IOManager.h"
namespace neutrino_implement {

  // Template instantiation for IO
  template<>
  inline std::string product_unique_name<neutrino_implement::EventParticle>() { return "particle"; }
  // template<>
  // inline EventParticle& IOManager::get_data(const std::string&);
  // template<>
  // inline EventParticle& IOManager::get_data(const ProducerID_t);

  /**
     \class neutrino_implement::EventParticle
     \brief A concrete factory class for neutrino_implement::EventParticle
  */
  class EventParticleFactory : public DataProductFactoryBase {
  public:
    /// ctor
    EventParticleFactory()
    { DataProductFactory::get().add_factory(product_unique_name<neutrino_implement::EventParticle>(),this); }
    /// dtor
    ~EventParticleFactory() {}
    /// create method
    EventBase* create() { return new EventParticle; }
  };


}


#endif
/** @} */ // end of doxygen group
