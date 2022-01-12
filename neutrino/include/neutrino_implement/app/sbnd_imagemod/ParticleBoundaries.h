
// #ifndef __PARTICLEBOUNDARIES_H__
// #define __PARTICLEBOUNDARIES_H__

// #include "neutrino_implement/core/Processor/ProcessBase.h"
// #include "neutrino_implement/core/Processor/ProcessFactory.h"
// namespace neutrino_implement {

//   /**
//      \class ProcessBase
//      User defined class ParticleBoundaries ... these comments are used to generate
//      doxygen documentation!
//   */
//   class ParticleBoundaries : public ProcessBase {

//   public:

//     /// Default constructor
//     ParticleBoundaries(const std::string name="ParticleBoundaries");

//     /// Default destructor
//     ~ParticleBoundaries(){}

//     void configure(const PSet&);

//     void initialize();

//     bool process(IOManager& mgr);

//     void finalize();

//   private:

//     std::string _cluster_producer;
//     std::string _particle_producer;
//     std::string _output_producer;
//     float _voxel_threshold;

//   };

//   /**
//      \class neutrino_implement::BBoxFromCluster3DFactory
//      \brief A concrete factory class for neutrino_implement::ParticleBoundaries
//   */
//   class ParticleBoundariesProcessFactory : public ProcessFactoryBase {
//   public:
//     /// ctor
//     ParticleBoundariesProcessFactory() { ProcessFactory::get().add_factory("ParticleBoundaries",this); }
//     /// dtor
//     ~ParticleBoundariesProcessFactory() {}
//     /// creation method
//     ProcessBase* create(const std::string instance_name) { return new ParticleBoundaries(instance_name); }
//   };

// }

// #endif
// /** @} */ // end of doxygen group
