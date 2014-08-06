WEEK_DAY_CHOICES = (
        (1, 'Sunday'),
        (2, 'Monday'),
        (3, 'Tuesday'),
        (4, 'Wednesday'),
        (5, 'Thursday'),
        (6, 'Friday'),
        (7, 'Saturday'),
    )

MONTH_WEEK_CHOICES = (
        (1, 'First'),
        (2, 'Second'),
        (3, 'Third'),
        (4, 'Fourth'),
        (5, 'Fifth'),
        
    )

MONTH_CHOICES = (
        (1, 'January'),
        (2, 'February'),
        (3, 'March'),
        (4, 'April'),
        (5, 'May'),
        (6, 'June'),
        (7, 'July'),
        (8, 'August'),
        (9, 'September'),
        (10, 'October'),
        (11, 'November'),
        (12, 'December')
    )

MONTH_DAY_COUNT_CHOICES = (
        (29, '29'),
        (30, '30'),
        (31, '31'),
    )

DAY_OF_MONTH_CHOICES = tuple((n, str(n)) for n in range(1, 32))

WEEKEND_ADJUSTMENT_CHOICES = (
        (1, 'None'),
        (2, 'NextWeekDay'),
        (3, 'PriorWeekDay'),
        (4, 'ClosestWeekDay'),
        (5, 'Default')
    )