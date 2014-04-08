
#ifndef OP_INTROSPECTOR_COMPOUNDNODE_H_
#define OP_INTROSPECTOR_COMPOUNDNODE_H_

#include <memory>

class ICompound;

namespace op {
namespace intro {

class CompoundNode final {

  public:

    using CompoundNodePtr = std::shared_ptr<CompoundNode>;
    using CompoundNodeList = std::list<CompoundNodePtr>;

    CompoundNode ();

    void set_compound (ICompound *the_compound);
    ICompound* compound () const;

    void AddChild (const CompoundNodePtr& the_child);

  private:

    ICompound *compound_;
    CompoundNodeList children_;

  public:

    auto begin () -> decltype(children_.begin());
    auto end () -> decltype(children_.end());

};

CompoundNode::CompoundNode ()
  : compound_(nullptr) {}

void CompoundNode::set_compound (ICompound *the_compound) {
  // FIXME: should not allow the compound pointer to change after it's been set.
  compound_ = the_compound;
}

ICompound* CompoundNode::compound () const {
  return compound_;
}

void CompoundNode::AddChild (const CompoundNodePtr& the_child) {
  children_.push_back(the_child);
}

auto CompoundNode::begin () -> decltype(children_.begin()) {
  return children_.begin();
}

auto CompoundNode::end () -> decltype(children_.end()) {
  return children_.end();
}

} // namespace intro
} // namespace op

#endif // OP_INTROSPECTOR_COMPOUNDNODE_H_

