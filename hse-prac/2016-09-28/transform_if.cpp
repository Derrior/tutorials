template <typename InIter, typename OutIter,
          typename Predicate, typename Operator>
OutIter transform_if(InIter first, InIter last,
                     OutIter out, Predicate condition, Operator f) {
    while (first != last) {
        if (condition(*first)) {
            *out++ = f(*first);
        }
        first++;
    }
    return out;
}

