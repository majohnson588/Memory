int main()
{
	//代码1
	int num = 0;
	scanf("%d", &num);
	int arr[num] = { 0 };//c99标准中的变长数组
	//代码2
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (ptr != NULL)//判断ptr指针是否为空
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//释放ptr所指向的动态内存
	ptr = NULL;
	return 0;
}

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("calloc");//打印内存分配错误原因
		return 1;
	}
	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}

int main()
{
    int* p = (int*)malloc(40);

    if (p == NULL)
    {
        perror("malloc");
        return 1;
    }
    使用
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;//0 1 2 3 4 5 6 7 8 9
    }

    空间不够，希望能放20个元素，考虑扩容
    int* ptr = (int*)realloc(p, 80);
    if (ptr != NULL)
    {
        p = ptr;
    }

    扩容成功了，开始使用

    不再使用，就释放
    free(p);
    p = NULL;

    return 0;
}

int main()
{
	int* p = (int*)malloc(1000);
	int i = 0;
	if (p = NULL)
	{
		//...
		return 1;
	}
	//使用
	for (i = 0; i < 250; i++)
	{
		*(p + i) = i;
	}

	free(p);
	p = NULL;

	return 0;
}

int main()
{
	int* p = (int*)malloc(100);
	int i = 0;
	if (p == NULL)
	{
		//...
		return 1;
	}
	//使用
	//越界访问
	for (i = 0; i <= 25; i++)
	{
		*(p + i) = i;
	}
	return 0;
}

int main()
{
	int* p = (int*)malloc(100);
	if (p == NULL)
	{
		*p = 1;
		p++;
	}
	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p = i;
		p++;
	}
	//释放空间
	free(p);
	p = NULL;

	return 0;
}

int main()
{
	int a = 10;
	int* p = &a;
	//......

	free(p);
	p = NULL;
	return 0;
}

int main()
{
	int* p = malloc(100);
	if (p = NULL)
		return 1;
	free(p);
	//...
	free(p);//err

	p = NULL;

	return 0;
}

void test()
{
	int* p = malloc(100);
	//使用
	if (1)
		return 1;

	free(p);
	p = NULL;
}

int main()
{
	test();
	//......
	while (1)
	{
		;
	}

	return 0;
}

void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello World");
	printf(str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

char* GetMemory(void)
{
	char p[] = "Hello World";
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}

int main()
{
	Test();
	return 0;
}

char* GetMemory(void)
{
	char p[] = "Hello World";
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}

int main()
{
	test();
	return 0;
}

void GetMemory(char** p, int num)
{
	assert(*p);

	*p = (char*)malloc(num);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}

void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}
