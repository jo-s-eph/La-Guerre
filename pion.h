#include <string>

class Pion {
public:
    Pion(int x, int y, int pv);
    virtual ~Pion() = default;
    
    virtual void deplacer(int newX, int newY);
    virtual void attaquer(Pion& cible);
    
    int getX() const;
    int getY() const;
    int getPv() const;
    
protected:
    int x, y;
    int pv;
};
