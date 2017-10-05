#include "Population.hpp"

Population::Population() {}

Population::Population(Map &map, const int popSize, const int generateMode)
{
    for (int i = 0; i < popSize; i++)
    {
        pop.push_back(Tour(map, generateMode));
    }
}

vector<Tour> &Population::getPop() { return (pop); }

Tour Population::elitism()
{
    double maxFit{maxFitness(pop)};
    int i = 0;
    for (Tour t : (pop))
    {
        if (compareDouble(t.getFitness(), maxFit))
        {
            Tour tmp = t;
            pop.erase(pop.begin() + i);
            return (tmp);
        }
        i++;
    }
}

void Population::crossoverOX(const int a, const int b)
{
    // Generate a random point of "cut" for realize OX.

    Tour tmp1{pop[a]}, tmp2{pop[b]};
    vector<City> order1, order2;
    int size{(int)pop[0].getRoute().size()}, ctrl1{0}, ctrl2{0}, cutPoint{rand() % size};

    while (cutPoint == 0 || cutPoint == size - 1)
    {
        cutPoint == rand() % size;
    }

    for (int i = cutPoint; i < size; i++)
    { // Generation of "tails" in offsprings
        pop[a].getRoute()[i] = tmp2.getRoute()[i];
        order1.push_back(tmp2.getRoute()[i]);
        pop[b].getRoute()[i] = tmp1.getRoute()[i];
        order2.push_back(tmp1.getRoute()[i]);
    }

    for (int i = 0; i < size; i++)
    { // Generation of first positions in offspring
        if (!contains(order1, tmp1.getRoute()[i]))
        { // If city not contains in offspring
            pop[a].getRoute()[ctrl1] = tmp1.getRoute()[i];
            ctrl1++;
        }

        if (!contains(order2, tmp2.getRoute()[i]))
        { // Samething
            pop[b].getRoute()[ctrl2] = tmp2.getRoute()[i];
            ctrl2++;
        }
    }
}

void Population::crossoverPMX(const int a, const int b)
{
    // Generate a two random points to execute de cross

    Tour tmp1{pop[a]}, tmp2{pop[b]};
    int size{(int)pop[0].getRoute().size()}, index1{rand() % size}, index2{rand() % size};

    if (index1 > index2)
    {
        int aux = index2;
        index2 = index1;
        index1 = aux;
    }

    for (int i = index1; i < index2; i++)
    {
        pop[a].swapCities(i, pop[a].findCity(tmp2.getRoute()[i]));
        pop[a].getRoute()[i] = tmp2.getRoute()[i];

        pop[b].swapCities(i, pop[b].findCity(tmp1.getRoute()[i]));
        pop[b].getRoute()[i] = tmp1.getRoute()[i];
    }
}

ostream &operator<<(ostream &output, Population &pop)
{ // Overload de operador para impressão da população
    int i{0};
    for (Tour t : pop.getPop())
    {
        output << "Tour " << setfill('0') << setw(3) << i << endl;
        output << t << endl;
        ++i;
    }
    return (output);
}
