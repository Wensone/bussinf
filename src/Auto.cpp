#include "../headers/Auto.h"

int Auto::number = 1;


void Auto::Generate(list <Auto> &lst)
{

}

ostream &operator<<(ostream &os, const Auto &o)
{
    os << o.mark << " / "
       << o.outMark << "/ "
       << o.inMark << "/ "
       << o.defects << "/ "
       << o.engine << "/ "
       << o.power << "/ "
       << o.year << " / "
       << o.type << " / "
       << o.name_auc << " / "
       << o.date << " / "
       << o.first_price << " / "
       << o.end_price << " / "
       << o.last_sold;
    return os;
}

void Auto::read(ifstream &in)
{

}

bool Auto::cmp(Auto &b)
{
    short c = 0;
    if (this->mark.size() > 1) ++c;
    if (this->power.size() > 1) ++c;
    if (this->outMark.size() > 1) ++c;
    if (this->year.size() > 1) ++c;
    if (this->defects.size() > 1) ++c;
    if (this->inMark.size() > 1) ++c;
    if (this->engine.size() > 1) ++c;
    if (this->type.size() > 1) ++c;
    if (this->name_auc.size() > 1) ++c;
    if (this->date.size() > 1) ++c;
    if (this->end_price.size() > 1) ++c;
    if (this->last_sold.size() > 1) ++c;
    if (this->first_price.size() > 1) ++c;

    if (this->mark.size() > 1 && this->mark == b.mark) --c;
    if (this->power.size() > 1 && this->power == b.power) --c;
    if (this->outMark.size() > 1 && this->outMark == b.outMark) --c;
    if (this->year.size() > 1 && this->year == b.year) --c;
    if (this->defects.size() > 1 && this->defects == b.defects) --c;
    if (this->inMark.size() > 1 && this->inMark == b.inMark) --c;
    if (this->engine.size() > 1 && this->engine == b.engine) --c;
    if (this->type.size() > 1 && this->type == b.type) --c;
    if (this->name_auc.size() > 1 && this->name_auc == b.name_auc) --c;
    if (this->date.size() > 1 && this->date == b.date) --c;
    if (this->end_price.size() > 1 && this->end_price == b.end_price) --c;
    if (this->last_sold.size() > 1 && this->last_sold == b.last_sold) --c;
    if (this->first_price.size() > 1 && this->first_price == b.first_price) --c;

    return (c == 0);
}

Auto::Auto()
{
    type = name_auc = date = first_price = end_price = last_sold = mark = power = outMark = defects = year = inMark = engine = "";
}

int Auto::getNumber()
{
    return number;
}

bool Auto::setNumber(int pole)
{
    if (pole < 1 || pole > 13)
        return false;
    Auto::number = pole;
    return true;
}

bool Auto::operator<(const Auto &rhs) const
{
    if (number == 1) return mark < rhs.mark;
    if (number == 2) return outMark < rhs.outMark;
    if (number == 3) return inMark < rhs.inMark;
    if (number == 4) return defects < rhs.defects;
    if (number == 5) return engine < rhs.engine;
    if (number == 6) return power < rhs.power;
    if (number == 7) return year < rhs.year;
    if (number == 8) return type < rhs.type;
    if (number == 9) return name_auc < rhs.name_auc;
    if (number == 10) return date < rhs.date;
    if (number == 11) return first_price < rhs.first_price;
    if (number == 12) return end_price < rhs.end_price;
    return last_sold < rhs.last_sold;
}

void Auto::setMark(const string &mark)
{
    Auto::mark = mark;
}

void Auto::setOutMark(const string &outMark)
{
    Auto::outMark = outMark;
}

void Auto::setInMark(const string &inMark)
{
    Auto::inMark = inMark;
}

void Auto::setDefects(const string &defects)
{
    Auto::defects = defects;
}

void Auto::setEngine(const string &engine)
{
    Auto::engine = engine;
}

void Auto::setPower(const string &power)
{
    Auto::power = power;
}

void Auto::setYear(const string &year)
{
    Auto::year = year;
}

void Auto::setType(const string &type)
{
    Auto::type = type;
}

void Auto::setName_auc(const string &name_auc)
{
    Auto::name_auc = name_auc;
}

void Auto::setDate(const string &date)
{
    Auto::date = date;
}

void Auto::setFirst_price(const string &first_price)
{
    Auto::first_price = first_price;
}

void Auto::setEnd_price(const string &end_price)
{
    Auto::end_price = end_price;
}

void Auto::setLast_sold(const string &last_sold)
{
    Auto::last_sold = last_sold;
}

bool Auto::operator==(const Auto &rhs) const
{
    return mark == rhs.mark &&
           outMark == rhs.outMark &&
           inMark == rhs.inMark &&
           defects == rhs.defects &&
           engine == rhs.engine &&
           power == rhs.power &&
           year == rhs.year &&
           type == rhs.type &&
           name_auc == rhs.name_auc &&
           date == rhs.date &&
           first_price == rhs.first_price &&
           end_price == rhs.end_price &&
           last_sold == rhs.last_sold;
}

bool Auto::operator!=(const Auto &rhs) const
{
    return !(rhs == *this);
}