#ifndef Geometry_TrackerGeometryBuilder_PixelGeomDetUnit_H
#define Geometry_TrackerGeometryBuilder_PixelGeomDetUnit_H

#include <boost/shared_ptr.hpp>

#include "Geometry/CommonDetUnit/interface/TrackerGeomDet.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "Geometry/TrackerGeometryBuilder/interface/ProxyPixelTopology.h"

class PixelGeomDetType;
class PixelTopology;
class SurfaceDeformation;
/**
 * The base PixelGeomDetUnit. Specialized in SiPixelGeomDetUnit.
 */

class PixelGeomDetUnit final : public TrackerGeomDet {
public:

  PixelGeomDetUnit(BoundPlane* sp, PixelGeomDetType const * type, DetId id);

  // DetUnit interface

  /// NOTE (A.M.): The actual pointer to PixelGeomDetType is now a member of the
  /// proxy topology. As PixelGeomDetType has the actual topology as a pointer,
  /// it is possible to access this topology in two different ways. Once via
  /// the proxy topology (through topology() and specificTopology()) which includes
  /// corrections for the surface deformations, and once via the GeomDetType
  /// (through type().topology() and the like).
  virtual const GeomDetType& type() const override;
  
  /// Returns a reference to the pixel proxy topology
  virtual const Topology& topology() const override;

  /// NOTE (A.M.): The actual pointer to PixelGeomDetType is now a member of the
  /// proxy topology. As PixelGeomDetType has the actual topology as a pointer,
  /// it is possible to access this topology in two different ways. Once via
  /// the proxy topology (through topology() and specificTopology()) which includes
  /// corrections for the surface deformations, and once via the GeomDetType
  /// (through type().topology() and the like).
  virtual const PixelGeomDetType& specificType() const;

  /// Returns a reference to the pixel proxy topology
  virtual const PixelTopology& specificTopology() const;

  /// Return pointer to surface deformation.
  virtual const SurfaceDeformation * surfaceDeformation() const { 
    return theTopology->surfaceDeformation();
  }

  bool isLeaf()	const override	{ return true;}

private:

  /// set the SurfaceDeformation for this StripGeomDetUnit to proxy topology.
  virtual void setSurfaceDeformation(const SurfaceDeformation * deformation);

  std::unique_ptr<ProxyPixelTopology> theTopology;
};

#endif // Tracker_PixelGeomDetUnit_H
