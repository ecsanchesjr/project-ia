#include "Population.hpp"

Population::Population() {}

Population::Population(Map &map, const int popSize, const int generationMethod)
{
    for (int i = 0; i < popSize; i++)
    {
        pop.push_back(Tour(map, generationMethod));
    }
}

Population *Population::newGeneration()
{
    Population *newGen = new Population;

    Population *aux = new Population;
    aux->getPop() = pop;
    for (int i = 0; i < ELITISM_TOTAL; i++)
    { // Get the N best Tours of Population, the population continues with tours to selection method
        elitismTours.push_back(aux->elitism());
    }
    delete aux;

    for (int i = 0; i < pop.size() - ELITISM_TOTAL; i++)
    {
        (*newGen).getPop().push_back(roulete());
    }
    newGen->crossover();
    newGen->mutate();

    /*   for (int i = 0; i < ELITISM_TOTAL; i++)
    { // erro na pop, dar um run pra klembrar, mas parece uqe o elitism não tá sendo inserido
        (*newGen).getPop().push_back(elitismTours[i]);
    } */
    for (Tour t : elitismTours)
    {
        (*newGen).getPop().push_back(t);
    }
    elitismTours.clear();
    return (newGen);
}

vector<Tour> &Population::getPop()
{
    return (pop);
}

void Population::crossover()
{
    int size{(int)pop.size()};

    if (CROSS_METHOD == 0)
    {
        for (int i = 0; i < size; i++)
        {
            crossoverOX(rand() % size, rand() % size);
        }
    }
    else if (CROSS_METHOD == 1)
    {
        for (int i = 0; i < size; i++)
        {
            crossoverPMX(rand() % size, rand() % size);
        }
    }
    else
    { // Never catch in this Else
        cout << "CROSS_METHOD VALUE ERROR!!!!" << endl;
    }
}

void Population::mutate()
{
    for (int i = 0; i < pop.size(); i++)
    {
        mutation(i);
    }
}

Tour Population::roulete()
{
    double sumFitness{0.0}, ctrl{0.0};
    int random{0};

    for (Tour t : pop)
    { // Sum all fitness in all tours
        sumFitness += t.getFitness();
    }

    // Generate a random number, this number will chose a tour
    random = rand() % RES;
    ctrl = convertRanges(random, sumFitness);

    for (Tour t : pop)
    {
        ctrl -= t.getFitness();
        if (ctrl <= 0)
        {
            return (t);
        }
    }
    return (pop[pop.size() - 1]);
}

Tour Population::elitism()
{
    double maxFit{maxFitness(this->pop)};
    int i = 0;
    //cout << "max "<< maxFit << endl;
    for (Tour t : (this->pop))
    {
        /* cout << t.getFitness() <<endl;
        cout << compareDouble(t.getFitness(), maxFit) << endl; */
        if (compareDouble(t.getFitness(), maxFit))
        {
            Tour tmp = t;
            this->pop.erase(this->pop.begin() + i);
            return (tmp);
        }
        i++;
    }
}

void Population::mutation(const int t)
{
    int size{(int)pop[t].getRoute().size()};
    for (int i = 0; i < size; i++)
    {
        if (rand() % 100 + 1 <= MUT_PERCENTAGE)
        {                                                    // Mutation ocurrs or not
            pop[t].swapCities(rand() % size, rand() % size); // Altern two cities in Tour
        }
    }
}

void Population::crossoverOX(const int a, const int b)
{
    // Generate a random point of "cut" for realize OX.
    Tour tmp1{pop[a]}, tmp2{pop[b]};
    vector<City> order1, order2;
    int size{(int)pop[0].getRoute().size()}, ctrl1{0}, ctrl2{0}, cutPoint{rand() % size};

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
