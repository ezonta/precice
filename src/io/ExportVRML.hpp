#ifndef PRECICE_IO_EXPORTVRML_HPP_
#define PRECICE_IO_EXPORTVRML_HPP_

#include "Export.hpp"
#include "logging/Logger.hpp"
#include <string>
#include <map>

namespace precice {
  namespace mesh {
     class Vertex;
     class Edge;
     class Triangle;
  }
}

// ----------------------------------------------------------- CLASS DEFINITION

namespace precice {
namespace io {

/**
 * @brief Writes polygonal or triangulated meshes to vrml 1.0 files.
 */
class ExportVRML : public Export
{
public:

  /**
   * @brief Standard constructor
   */
  ExportVRML ( bool plotNormals );

  /**
   * @brief Returns export type ID, i.e., VRML.
   */
  virtual int getType() const;

  /**
   * @brief Perform writing to VRML file
   */
  virtual void doExport (
    const std::string& name,
    const std::string& location,
    mesh::Mesh&        mesh );

  /**
   * @brief Perform writing to VRML file of a full mesh checkpoint.
   *
   * A full checkpoint also  includes vertex data and property containers.
   */
  void doExportCheckpoint (
    const std::string& filename,
    mesh::Mesh&        mesh );

private:

  mutable logging::Logger _log{"io::ExportVTML"};

  void openFile (
    std::ofstream&     outFile,
    const std::string& filename ) const;

  void writeHeader ( std::ofstream& outFile ) const;

  void writeMesh (
    std::ofstream& outFile,
    mesh::Mesh&    mesh ) const;

  void writeVertexData (
    std::ofstream& outFile,
    mesh::Mesh&    mesh ) const;

  void writePropertyContainer (
    std::ofstream& outFile,
    mesh::Mesh&    mesh ) const;
};

}} // namespace precice, io

#endif /* PRECICE_IO_EXPORTVRML_HPP_ */
