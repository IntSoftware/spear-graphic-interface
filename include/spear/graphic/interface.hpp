#ifndef SPEAR_GRAPHIC_INTERFACE_HPP
#define SPEAR_GRAPHIC_INTERFACE_HPP

#define SGI_VERSION_MAJOR 0
#define SGI_VERSION_MINOR 0
#define SGI_VERSION_PATCH 1

#include <memory>
#include <string>

namespace spear::graphics {

class GraphicEngineGlobal {
public:
    virtual bool initialize() = 0;
    virtual void shutdown() = 0;
    virtual ~GraphicEngineGlobal() = default;
};

GraphicEngineGlobal& global();

class GraphicEngine;
class Window;
class RenderObject;

class GraphicEngine {
public:
  virtual ~GraphicEngine() = default;

  // Engine lifecycle
  virtual bool initialize() = 0;
  virtual void shutdown() = 0;

  // Window management
  virtual std::shared_ptr<Window> createWindow(const std::string &title,
                                               int width,
                                               int height) = 0;

  virtual void destroyWindow(std::shared_ptr<Window> window) = 0;

  
  virtual void renderFrame() = 0;
  virtual void resize(int width, int height) = 0;

  virtual void addObject(std::shared_ptr<RenderObject> object) = 0;
  virtual void removeObject(std::shared_ptr<RenderObject> object) = 0;
};

std::unique_ptr<GraphicEngine> createGraphicEngine();

} // namespace spear::graphics

#endif // SPEAR_GRAPHIC_INTERFACE_HPP
