37 12 85 20 45 79 3 68 50 10
[37, 12, 85, 20, 45, 79, 3, 68, 50, 10]

1st call
{
	pairs [37,12] [85, 20] [45, 79] [3, 68] [50, 10]
	larger [37, 85, 79, 68, 50]
	smaller [12, 20, 45, 3, 10]
}

[37, 85, 79, 68, 50]
2nd call
{
	pairs [37, 85] [79, 68] 50
	larger [85, 79]
	smaller [37, 68]
	leftovers  50
}

[85, 79]
3rd call
{
	pairs [85, 79]
	larger [85]
	smaller [79]
}

unwinding
order {0}
1st call
{
	larger [85]
	smaller[79]
	mainChain [79, 85]
}

[79, 85]
order {1, 0}
2nd call
{
	leftovers [50]
	larger [79, 85]
	smaller[37, 68]
	mainChain[79, 85]
	mainChain[68, 79, 85]
	mainChain[37, 68, 79, 85]
	mainChain[37, 50, 68, 79, 85]
}

[37, 50, 68, 79, 85]
order {1, 3, 0, 2, 4}
3rd call
{
	smaller [12, 20, 45, 3, 10]
	larger [37, 50, 68, 79, 85] 
	mainChain[37, 50, 68, 79, 85]
	mainChain[20, 37, 50, 68, 79, 85]
	mainChain[3, 20, 37, 50, 68, 79, 85]
	mainChain[3, 12, 20, 37, 50, 68, 79, 85]
	mainChain[3, 12, 20, 37, 45, 50, 68, 79, 85]
	mainChain[3, 10, 12, 20, 37, 45, 50, 68, 79, 85]
}







