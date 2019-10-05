template<typename T, typename allocator>
class List;

template<typename T>
class Link{
    template<typename U, typename A>
    friend class List;
    T val;
    Link * succ;
    Link * prev;
};

template<typename T, typename Allocator>
class List{
    // Definitions.
};