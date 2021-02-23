#ifndef VISITOR_H
#define VISITOR_H

class Mary;
class Bob;

class Visitor
{
    public: 
        virtual void visit_bob(const Bob* bob) const = 0;
        virtual void visit_mary(const Mary* mary) const = 0;

};

#endif // VISITOR_H
