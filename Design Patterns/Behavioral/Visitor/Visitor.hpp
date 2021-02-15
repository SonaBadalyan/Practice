#ifndef VISITOR_H
#define VISITOR_H

class Sona;
class Meruzhan;

class Visitor
{
    public: 
        virtual void visit_meruzhan(const Meruzhan* morexik) const = 0;
        virtual void visit_sona(const Sona* xelarik) const = 0;

};

#endif // VISITOR_H
