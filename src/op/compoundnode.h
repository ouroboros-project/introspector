
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

    const std::string& name () const;
    bool ok () const;

    void Check (const ICompound* the_name);

    void AddChild (const Ptr& the_child);

    void AddChild (ICompound* the_child_compound);

    Ptr FindChild (const std::string& the_name) const;

    void DumpTree (std::ostream& out, const std::string& ident = "") const;

    void Translate (std::ostream& out, const std::string& ident = "") const;

  private:

    const std::string name_;
    std::string       type_;
    bool              ok_;
    Table             children_;

  public:

    auto begin () const -> decltype(children_.begin());
    auto end () const -> decltype(children_.end());

};

inline CompoundNode::CompoundNode (const std::string& the_name)
  : name_(the_name), type_(""), ok_(false) {}

inline const std::string& CompoundNode::name () const {
  return name_;
}

inline bool CompoundNode::ok () const {
  return ok_;
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

