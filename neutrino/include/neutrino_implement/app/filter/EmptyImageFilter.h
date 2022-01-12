
#ifndef __NEUTRINO_IMPLEMENT_FILTER_EMPTYIMAGEFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_EMPTYIMAGEFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class EmptyImageFilter ... these comments are used to generate
     doxygen documentation!
  */
  class EmptyImageFilter : public neutrino_implement::ProcessBase {

  public:

    /// Default constructor
    EmptyImageFilter(const std::string name="EmptyImageFilter");

    /// Default destructor
    ~EmptyImageFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:
    std::string _image_producer;

  };

  /**
     \class neutrino_implement::EmptyImageFilterFactory
     \brief A concrete factory class for neutrino_implement::EmptyImageFilter
  */
  class EmptyImageFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    EmptyImageFilterProcessFactory() { ProcessFactory::get().add_factory("EmptyImageFilter",this); }
    /// dtor
    ~EmptyImageFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new EmptyImageFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
