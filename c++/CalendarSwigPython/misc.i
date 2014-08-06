%exception; 
//namespace std {
//%rename(VectorDateImpl) VectorDate ;
%template(VectorDateImpl) std::vector<Date>;

//%rename(SetDateImpl) SetDate;
%template(SetDateImpl) std::set<Date>;

//%rename(SetWeekDayImpl) SetWeekDay
%template(SetWeekDayImpl) std::set<WeekDay::eWeekDay>;

//%rename(SetStringImpl) std::set<String>;
%template(SetStringImpl) std::set<String>;

%template (CalendarRulesImpl) std::set<CalendarRuleSharedPtr, CalendarRuleSharedPtrLessThan>;
//}