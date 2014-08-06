# Create your views here.



from django.db.models import Q
from django.shortcuts import render_to_response
from models import CalendarRule

def search(request):
    query = request.GET.get('q', '')
    if query:
        qset = (
            Q(name__icontains=query)
        )
        results = CalendarRule.objects.filter(qset).distinct()
    else:
        results = []
    return render_to_response("dates/search.html", {
        "results": results,
        "query": query
    })
