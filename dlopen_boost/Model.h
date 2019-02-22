#ifndef MODEL_H_
#define MODEL_H_

class Model {
  public:
    Model();

    virtual ~Model();

  public:
    virtual int getSizeInit() = 0;

    virtual void init(int size) = 0;

    int getSize();

  protected:
    int size_;
};

#endif // MODEL_H_
