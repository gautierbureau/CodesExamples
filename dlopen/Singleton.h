#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton {
  public:

    Singleton();

    ~Singleton();

    static Singleton singleton_instance;

    void add();

  private:

    int count_;
};

class SingletonAdd {
  public:

    SingletonAdd();

    ~SingletonAdd();

    void add();
};

#endif
