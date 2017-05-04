#ifndef FACTORY_H_
#define FACTORY_H_

#include <map>
#include <string>
#include <vector>

class Model;
class Factories;

class Factory {
 public:

    Factory() { std::cout << "Factory::Factory" << std::endl; }

    virtual ~Factory() { std::cout << "Factory::~Factory" << std::endl; }

    virtual Model* create() const = 0;

    virtual void destroy(Model*) const = 0;

    static Model* createModelFromLib(const std::string& lib);

    static void resetFactories();

    void* handle_; ///< handle return by dlopen when the library is loaded

    static std::vector<Model*> models_;

 private:
    static Factories factories_;  ///< Factories already available

};

class Factories {
  public:

    Factories();

    ~Factories();

    std::map<std::string, Factory*>::iterator find(const std::string& lib);

    bool end(std::map<std::string, Factory*>::iterator & iter);

    void add(const std::string& lib, Factory* factory);

    void reset();

  private:
    std::map<std::string, Factory*> factoryMap_; ///< associate a library factory with the name of the library*
};

#endif // Factory_H_
