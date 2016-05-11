#ifndef UTOPIA_SHADER_H
#define UTOPIA_SHADER_H

#include <GL/glew.h>

#include <SFML/OpenGL.hpp>
#include <vector>
#include <string>

namespace utopia
{

/**
  * class which load shaders and create program.
  * this class will load shaders, but shader name must be "shader" and file
  * extension  must follow these rules:
  *
  * vertex_shader                :vert.glsl
  * fragment_shaader             :frag.glsl
  * geometry_shader              :geom.glsl
  * tesselation_evaluation_shader:tesseval.glsl
  * tesselation_control_shader   :tesscont.glsl
  *
  * e.g: geometry shader will be name shader.geom.glsl
  */
  class ShaderProgram
  {
  public:
 /**
   * @brief creating shaders from path.
   * @param(resPath) path with containg shaders sources.
   * @param(shadersKind) enum with contain all kind of shaders you will may need.
   *
   * This constructor load all shader sources from path checking kinds of shader
   * you passing in shaders param, in e.g: resPath = shaders/scene1/water/,
   * and shadersKind = GL_VERTEX_SHADER | GL_TESS_CONTROL_SHADER |
   * GL_TESS_EVALUATION_SHADER | GL_FRAGMENT_SHADER, the constructor will take
   * all enum and search on resPath for all shaders with name shader.vert.glsl
   * for vertex shader, shader.tesseval.glsl for tesselation evaluation shader,
   * and so on.
   */
   ShaderProgram(const std::string resPath,
                 const std::vector<GLenum> &shadersKind);

  /**
    * @brief crating each shader contained in shadersKind fallowing the vector
    * and opengl graphics pipepeline
    * @param(pathList) vector containing each path to every shader wich you
    * passed on shadersKind
    * @param(shadersKind) enum contaning all shaders kind you will may need.
    *
    * Everything like other constructor, but every shader are created
    * fallowing opengl pipeline and what shaders kind you passed, e.g:
    * shadersKind = GL_VERTEX_SHADER | GL_FRAGMENT_SHADER | GL_GEOMETRY_SHADER,
    * the constructor will fallow the first path on list to create the vertex
    * shader, the second path to create geometry shader, and at last fragment
    * shader. if there are any doubts about opengl pipeline google it ^^
    */
    ShaderProgram(const std::vector<std::string> &pathList,
                  const std::vector<GLenum> &shadersKind);

    ShaderProgram();

  /**
    * Default destructor which will call everything will need to destry the
    * shaders.
    */
    virtual ~ShaderProgram();

    void load(const std::string resPath,
              const std::vector<GLenum> &shadersKind);

    void load(const std::vector<std::string> &pathList,
              const std::vector<GLenum> &shadersKind);

  /**
    * Bind the program to use
    */
    void bind() const;

    GLuint programID() const;
   /**
    * @param name name of location to return this own id.
    *
    * return the location id of a uniform variable of the shader
    */
    GLint uniformLocation(std::string name);

  protected:
    std::vector<GLuint> shadersList;
    GLuint _program;
  };
}
#endif
