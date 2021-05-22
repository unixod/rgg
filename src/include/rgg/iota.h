#ifndef RGG_DETAILS_IOTA_H
#define RGG_DETAILS_IOTA_H



namespace rgg::details {

// A temporary analogue of std::ranges::iota to work around the compile time error:
//    > output range must use a RandomAccessIterator when input range does not meet
//    > the ForwardIterator requirements
// This issue happened when I tried to use std::ranges::sample with std::ranges::iota
// when sending output to std::ostream_iterator.
//
// See also: https://cplusplus.github.io/LWG/issue3291
template<std::integral BoundType>
class Iota {
public:
    struct Iter {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = decltype(std::declval<BoundType>() - std::declval<BoundType>());
        using value_type = BoundType;

        explicit Iter(BoundType a = {})
            : a_{a}
        {}

        Iter& operator++()
        {
            ++a_;
            return *this;
        }

        Iter operator++(int)
        {
            return a_++;
        }

        Iter& operator--()
        {
            --a_;
            return *this;
        }

        Iter operator--(int)
        {
            return a_--;
        }

        Iter& operator += (difference_type n)
        {
            a_ += n;
            return *this;
        }

        friend Iter operator + (Iter i, difference_type n)
        {
            i.a_ += n;
            return i;
        }

        friend Iter operator + (difference_type n, Iter i)
        {
            i.a_ -= n;
            return i;
        }

        Iter& operator -= (difference_type n)
        {
            a_ -= n;
            return *this;
        }

        friend Iter operator - (Iter i, difference_type n)
        {
            i.a_ -= n;
            return i;
        }

        friend auto operator - (const Iter& lhs, const Iter& rhs)
        {
            return lhs.a_ - rhs.a_;
        }

        auto operator[](difference_type n) const
        {
            return a_ + n;
        }

        auto operator* () const
        {
            return a_;
        }

        auto operator <=> (const Iter&) const = default;

    private:
        BoundType a_;
    };

    auto begin()
    {
        return Iter{lowerBound_};
    }

    auto end()
    {
        return Iter{upperBound_};
    }

    Iota(BoundType lowerBound, BoundType upperBound)
        : lowerBound_{lowerBound},
          upperBound_{upperBound}
    {}

private:
    BoundType lowerBound_;
    BoundType upperBound_;
};

} // namespace rgg::details

#endif // RGG_DETAILS_IOTA_H
