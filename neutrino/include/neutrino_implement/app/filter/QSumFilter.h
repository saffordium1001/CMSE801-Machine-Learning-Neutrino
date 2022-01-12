
#ifndef __NEUTRINO_IMPLEMENT_FILTER_QSUMFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_QSUMFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class QSumFilter ... these comments are used to generate
     doxygen documentation!
  */
  class QSumFilter : public ProcessBase {

  public:

    /// Default constructor
    QSumFilter(const std::string name="QSumFilter");

    /// Default destructor
    ~QSumFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:

    std::string _image_producer;
    std::vector<double> _min_qsum_v;
    std::vector<int>    _min_pixel_v;
    std::vector<double> _min_adc_v;

  };

  /**
     \class neutrino_implement::QSumFilterFactory
     \brief A concrete factory class for neutrino_implement::QSumFilter
  */
  class QSumFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    QSumFilterProcessFactory() { ProcessFactory::get().add_factory("QSumFilter",this); }
    /// dtor
    ~QSumFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new QSumFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
