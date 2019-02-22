#ifndef FACTORY_H_
#define FACTORY_H_

#include <map>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

class Model;
class Factories;

class Factory {
 public:

    Factory() { std::cout << "Factory::Factory" << std::endl; }

    virtual ~Factory() { std::cout << "Factory::~Factory" << std::endl; }

    virtual Model* create() const = 0;

    virtual void destroy(Model*) const = 0;

    static boost::shared_ptr<Model> createModelFromLib(const std::string& lib);

    void* handle_; ///< handle return by dlopen when the library is loaded

 private:
    static Factories factories_;  ///< Factories already available
};

typedef void destroy_t(Factory*);

class Factories {
  public:

    Factories();

    ~Factories();

    std::map<std::string, Factory*>::iterator find(const std::string& lib);

    bool end(std::map<std::string, Factory*>::iterator& iter);

    void add(const std::string& lib, Factory* factory);
    void add(const std::string& lib, destroy_t* deleteFactory);

  private:
    std::map<std::string, Factory*> factoryMap_; ///< associate a library factory with the name of the library*
    std::map<std::string, destroy_t*> factoryMapDestroy_;
};

class ModelDelete {
  public:

    ModelDelete(Factory* factory);

    ~ModelDelete() { std::cout << "ModelDelete::~ModelDelete()" << std::endl; }

    void operator() (Model* model);

    ModelDelete(const ModelDelete& modelDelete) : factory_(modelDelete.factory_) { std::cout << "ModelDelete(const ModelDelete& modelDelete)" << std::endl; };

    ModelDelete(ModelDelete& modelDelete) : factory_(modelDelete.factory_) { std::cout << "ModelDelete(ModelDelete& modelDelete)" << std::endl; };

  private:
    ModelDelete() { std::cout << "ModelDelete::ModelDelete()" << std::endl; }

    Factory* factory_;
};

#endif // Factory_H_
