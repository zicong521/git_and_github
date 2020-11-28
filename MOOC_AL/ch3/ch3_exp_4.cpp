
typedef  double DOUBLE ;
typedef  char CHAR ;
typedef struct{
    DOUBLE  aRangeLimit;
    CHAR    *pszGrade;
}T_GRADE_MAP;

T_GRADE_MAP gGradeMap[MAX_GRADE_LEVEL] = {
    {50.0,              "Fail"},
    {60.0,              "Pass"},
    {70.0,              "Credit"},
    {80.0,              "Distinction"},
    {100.0,             "High Distinction"}
};

static CHAR* EvaluateGrade(DOUBLE dScore)
{
    INT8U ucLevel = 0;
    for(; ucLevel < MAX_GRADE_LEVEL; ucLevel++)
    {
        if(dScore < gGradeMap[ucLevel].aRangeLimit)
            return gGradeMap[ucLevel].pszGrade;
    }
    return gGradeMap[0].pszGrade;
}