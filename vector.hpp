#ifndef VEKTOR_H
#define VEKTOR_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>



template <class T>
class Vector{
public:
    using size_type = size_t;
    
private:
    
    size_type sz;
    size_type max_sz;
    T* values;

public:
    // Konstruktoren
    Vector(): sz{0}, max_sz{0}, values{nullptr} { // leerer Konstruktor
    }
    
    Vector(std::size_t n): sz{0}, max_sz{n}{ // Konsttruktor mit größe
        values = new T[max_sz];
    }
    
    Vector(std::initializer_list<T> neu): Vector(neu.size()) { // vector{x,y};
        for(const auto v: neu)
            values[sz++] = v;
    }
    
    ~Vector(){ // Dekonstruktor
        delete[] values;
    }
    
    Vector (const Vector& kopieren){ // Kopierkonstruktor
        T* values_new = new T*[kopieren.max_sz];
        for(size_t i{0}; i<max_sz; i++)
            values_new[i] = kopieren[i];
        delete[] values;
        values = values_new;
    }
    
    //Funktionen
    size_type size() const{
        return sz;
    }
    
    bool empty() const{
        if(sz==0) return true;
        else return false;
    }
    
    void clear() {
        sz=0;
    }
    
    void reserve(size_type n){
        if(n>max_sz){
            T* values_new = new T[n];
            for(std::size_t i{0};i<sz;i++){
                values_new[i] = values[i];
            }
        delete[] values;
        values = values_new;
        max_sz=n;
        }
        else return;
    }
    
    void shrink_to_fit(){
        if(!(max_sz==sz)){
            T* values_new = new T[sz];
            for(std::size_t i{0};i<sz;i++){
                values_new[i] = values[i];}
        delete[] values;
        values = values_new;
       
        }
        
    }
    
    void push_back(T x){
        if(sz+1>max_sz){
            reserve(sz+1);
            values[sz] = x;
            sz++;
        }
        else{
            values[sz] = x;
            sz++;
        }
        
    }
    
    
    void pop_back() {
        if(sz==0) throw std::runtime_error("Zeile 95");
        else sz--;
    }
    
    T& operator[](size_t index) {
        if(index<0 || index>sz-1)
            throw std::runtime_error("invalid position");
        else
            return values[index];
     }
    
    const T& operator[](size_t index) const{ // bin mir nicht sicher was const macht noch fixen
        if(index<0 || index>sz-1)
            throw std::runtime_error("invalid position");
        else
            return values[index];
     }
    
    size_type capacity() const{
        return max_sz;
    }
    
    //friend std::ostream& operator<<(std::ostream& o,const Vector&);
    
    
    
    

    /*void reserve(size_type n){
        if(sz>=max_sz) return;
        pointer next{new value_type[n]}; // ändern anfänger ding
        for(std::size_t i{0};i<sz;i++)
            next[i] = values[i];
        delte values;
        values = next;
    }

    void clear(){
        
    }
    Vector& operator=(const Vektor v){ // Vektor v ist kopie daher okay
        std::swap(sz, v.sz);
        std::swap(max_sz, v.max_sz);
        std::swap(values, v.values);
        return *this;
        
    }*/
    
};
/*template <class T>
std::ostream& operator<<(std::ostream& o,const Vector<T>& x) {
    o << "[";
    bool first = true;
    for(std::size_t i{0}; i<x.sz; i++){
        if(first){
            first = false;
            o << x.values[i];
        }
        else{
            o << ", " << x.values[i];
        }
    }
    o << "]";
    return o;
}*/

#endif
