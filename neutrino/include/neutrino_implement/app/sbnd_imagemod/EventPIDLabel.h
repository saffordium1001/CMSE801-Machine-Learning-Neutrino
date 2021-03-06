
#ifndef __EVENTPIDLABEL_H__
#define __EVENTPIDLABEL_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
#include "neutrino_implement/core/dataformat/Tensor.h"
#include "neutrino_implement/core/dataformat/Particle.h"

namespace neutrino_implement {

/**
   \class ProcessBase
   User defined class EventPIDLabel ... these comments are
   used to generate
   doxygen documentation!
*/



class EventPIDLabel : public ProcessBase {

  enum interaction_type_t     {kNueCC, kNumuCC, kNC, kNEventCategories};
  enum proton_counter_t       {kZeroProtons, kOneProton, kNProtons, kNProtonCategories};
  enum charged_pion_counter_t {kZeroChargedPions, kNChargedPions, kNChargedPionCategories};
  enum neutral_pion_counter_t {kZeroNeutralPions, kNNeutralPions, kNNeutralPionCategories};

 public:
  /// Default constructor
  EventPIDLabel(
      const std::string name = "EventPIDLabel");

  /// Default destructor
  ~EventPIDLabel() {}

  void configure(const PSet&);

  void initialize();

  bool process(IOManager& mgr);

  void finalize();


 private:

  std::string _output_neutrino_id_producer;
  std::string _output_proton_id_producer;
  std::string _output_chrpion_id_producer;
  std::string _output_ntrpion_id_producer;
  std::string _particle_producer;
  std::string _neutrino_producer;

  float _proton_threshold;
  float _charged_pion_threshold;
  float _neutral_pion_threshold;

};

/**
   \class neutrino_implement::EventPIDLabelFactory
   \brief A concrete factory class for neutrino_implement::EventPIDLabel
*/
class EventPIDLabelProcessFactory
    : public ProcessFactoryBase {
 public:
  /// ctor
  EventPIDLabelProcessFactory() {
    ProcessFactory::get().add_factory("EventPIDLabel",
                                      this);
  }
  /// dtor
  ~EventPIDLabelProcessFactory() {}
  /// creation method
  ProcessBase* create(const std::string instance_name) {
    return new EventPIDLabel(instance_name);
  }
};
}

#endif
/** @} */  // end of doxygen group
