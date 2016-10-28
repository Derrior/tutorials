#include <functional>
template <typename Iterator, typename Transformation> 

Iterator Transform(Iterator begin, Iterator end,
                   Iterator output,
                   Transformation transformation) {
    while (begin != end) {
        *output++ = transformation(*begin++);
    }
    return output;
}
          

template <
          typename Iterator, typename Element,
          typename Comparator = std::less<typename std::iterator_traits
                                                   <Iterator>::value_type>
         > 

Iterator partition(Iterator begin, Iterator end, Element key,
                   Comparator cmp = Comparator()) {
    Iterator endFirstPartIterator = begin;
    Iterator currentPosition = begin;
    while (currentPosition != end) {
        if (cmp(*currentPosition, key)) {
            std::swap(*currentPosition, *endFirstPartIterator);
            endFirstPartIterator++;
        }
        currentPosition++;
    }
    return currentPosition;
}

template <
          typename Iterator, typename Predicat
         > 

Iterator partition_if(Iterator begin, Iterator end, Predicat function) {
    Iterator endFirstPartIterator = begin;
    Iterator currentPosition = begin;
    while (currentPosition != end) {
        if (function(*currentPosition)) {
            std::swap(*currentPosition, *endFirstPartIterator);
            endFirstPartIterator++;
        }
        currentPosition++;
    }
    return currentPosition;
}

template <typename Iterator, 
        typename Comparator = 
                std::less<typename std::iterator_traits
                                    <Iterator>::value_type> 
        >
Iterator merge(Iterator firstBegin, Iterator firstEnd, 
               Iterator secondBegin, Iterator secondEnd,
               Iterator outputBegin, Comparator cmp = Comparator()) {
    while (firstBegin != firstEnd && secondBegin != secondEnd) {
        if (cmp(*firstBegin, *secondBegin)) {
            *outputBegin = *firstBegin;
            *firstBegin++;
        } else {
            *outputBegin = *secondBegin;
            *secondBegin++;
        }
        outputBegin++;
    }
    copy(firstBegin, firstEnd, outputBegin);
    copy(secondBegin, secondEnd, outputBegin);
    return outputBegin;
}

template <typename Iterator, typename Predicat>

Iterator lowerbound(Iterator begin, Iterator end, Predicat function) {
    while (std::next(begin) != end) {
        Iterator middle = begin + distance(begin, end) / 2;
        if (function(*middle)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    if (function(begin)) {
        return begin;
    }
    return end;
}
