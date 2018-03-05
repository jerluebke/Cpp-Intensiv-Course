template <typename T>
const T binarySearch(const T A[], const int length, const T value)
{
	int start = 0;
	int end = length - 1;
	while (start <= end)
	{
		int middle = start + ((end - start) / 2);
		if (A[middle] == value)
			return middle;
		else if (A[middle] < value)
			start = middle + 1;
		else // A[middle] > value
			end = middle - 1;
	}
	return -1;
}
