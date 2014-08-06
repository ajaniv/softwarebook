_name_space_table = {
        1 : 'Other',
        2 : 'Calendar',
        3 : 'Calendar Rules',
        4 : 'Core',
        5 : 'Reference Data',
        6 : 'Date',
        7 : 'Todo',
        8 : 'Post',
        9 : 'Forum',
        10 : 'Event',
        11 : 'Art Exhibit',
                    }


NAME_SPACE_CHOICES = _name_space_table.items()
     

def name_space_display(value):
    return _name_space_table[value] 