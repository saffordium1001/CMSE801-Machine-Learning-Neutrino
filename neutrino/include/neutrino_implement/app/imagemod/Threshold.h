
#ifndef __NEUTRINO_IMPLEMENT__THRESHOLD_H__
#define __NEUTRINO_IMPLEMENT__THRESHOLD_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class Threshold ... these comments are used to generate
     doxygen documentation!
  */
  class Threshold : public ProcessBase {

  public:

    /// Default constructor
    Threshold(const std::string name="Threshold");

    /// Default destructor
    ~Threshold(){}

    void configure(const PSet&);

    void initialize();

    bool process(IOManager& mgr);

    void finalize();

  private:

    void configure_labels(const PSet&);

    // List of input producers:
    std::vector<std::string> _input_producer_v;
    // List of input datatypes:
    std::vector<std::string> _input_product_v;
    // List of output producers:
    std::vector<std::string> _output_producer_v;
    // List of thresholds per projection ID (or one global threshold for all)
    std::vector<float>       _thresholds_v;
  };

  /**
     \class neutrino_implement::ThresholdFactory
     \brief A concrete factory class for neutrino_implement::Threshold
  */
  class ThresholdProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    ThresholdProcessFactory() { ProcessFactory::get().add_factory("Threshold",this); }
    /// dtor
    ~ThresholdProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new Threshold(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
