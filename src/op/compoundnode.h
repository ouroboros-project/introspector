
#ifndef OP_INTROSPECTOR_COMPOUNDNODE_H_
#define OP_INTROSPECTOR_COMPOUNDNODE_H_

#include <memory>
#include <string>
#include <map>
#include <ostream>

class ICompound;

namespace op {
namespace intro {

class CompoundNode final : public std::enable_shared_from_this<CompoundNode> {

  public:

    using Ptr = std::shared_ptr<CompoundNode>;
    using Table = std::map<std::string, Ptr>;

    CompoundNode (const std::string& the_name);
    ~CompoundNode ();

    const std::string& name () const;
    void set_compound (ICompound *the_compound);
    const ICompound* compound () const;

    void AddChild (const Ptr& the_child);

    void AddChild (ICompound* the_child_compound);

    Ptr FindChild (const std::string& the_name) const;

    void DumpTree (std::ostream& out, const std::string& ident = "") const;

  private:

    const std::string name_;
    ICompound         *compound_;
    Table             children_;

  public:

    auto begin () const -> decltype(children_.begin());
    auto end () const -> decltype(children_.end());

};

inline CompoundNode::CompoundNode (const std::string& the_name)
  : name_(the_name), compound_(nullptr) {}

inline void CompoundNode::set_compound (ICompound *the_compound) {
  // FIXME: should not allow the compound pointer to change after it's been set.
  // FIXME: should not allow a compound with a name different from that of the
  //        node.
  compound_ = the_compound;
}

inline const std::string& CompoundNode::name () const {
  return name_;
}

inline const ICompound* CompoundNode::compound () const {
  return compound_;
}

inline auto CompoundNode::begin () const -> decltype(children_.begin()) {
  return children_.begin();
}

inline auto CompoundNode::end () const -> decltype(children_.end()) {
  return children_.end();
}

} // namespace intro
} // namespace op

#endif // OP_INTROSPECTOR_COMPOUNDNODE_H_

