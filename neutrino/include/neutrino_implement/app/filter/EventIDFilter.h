
#ifndef __NEUTRINO_IMPLEMENT_FILTER_EVENTIDFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_EVENTIDFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
#include <map>
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class EventIDFilter ... these comments are used to generate
     doxygen documentation!
  */
  class EventIDFilter : public neutrino_implement::ProcessBase {

  public:

    /// Default constructor
    EventIDFilter(const std::string name="EventIDFilter");

    /// Default destructor
    ~EventIDFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:


    std::map<neutrino_implement::EventID,bool> _id_m;
    std::string _ref_producer;
    std::string _ref_type;
    bool _remove_duplicate;
    std::string _fname;
    // int _run;
    // int _subrun;
    // int _event;
  };

  /**
     \class neutrino_implement::EventIDFilterFactory
     \brief A concrete factory class for neutrino_implement::EventIDFilter
  */
  class EventIDFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    EventIDFilterProcessFactory() { ProcessFactory::get().add_factory("EventIDFilter",this); }
    /// dtor
    ~EventIDFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new EventIDFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
