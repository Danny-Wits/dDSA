void towerOfHanoi(int n, Tower &start, Tower &end, Tower &intermediate)
{

    if (n > 0)
    {
        towerOfHanoi(n - 1, start, intermediate, end);
        moveFromTo(start, end);
        print();
        towerOfHanoi(n - 1, intermediate, end, start);
    }
}