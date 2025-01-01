#ifndef STORAGE_H
#define STORAGE_H


/**
 * @brief Interface para diferentes tipos de armazenamento, como listas, matrizes
 *
 * @tparam T Tipo de dado a ser armazenado, como arestas ou vertices
 */
template<class T>
class Storage {
public:
    virtual ~Storage() = default;

    virtual void add(T info){};
    virtual T get(int ID) { return nullptr; }
};



#endif //STORAGE_H
