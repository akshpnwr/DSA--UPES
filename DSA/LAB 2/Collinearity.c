int collinearity()
{

    int x1, y1, x2, y2, x3, y3;

    printf("Enter co-ordinates of first point (x1,y1): ");
    scanf("%d%d", &x1, &y1);

    printf("Enter co-ordinates of second point (x2,y2): ");
    scanf("%d%d", &x2, &y2);

    printf("Enter co-ordinates of thirs point (x3,y3): ");
    scanf("%d%d", &x3, &y3);

    float m1 = y2 - y1 / x2 - x1;
    float m2 = y3 - y2 / x3 - x2;

    if (m1 == m2)
        printf("\nPoints are collinear");
    else
        printf("\nPoints are non-collinear");

    return 0;
}
