
#include <op/compoundnode.h>

#include <sstream>
#include <iostream>
#include <utility>

#include <doxmlintf.h>

namespace op {
namespace intro {

using std::string;
using std::stringstream;
using std::ostream;
using std::cout;
using std::endl;
using std::hash;
using std::make_pair;

void CompoundNode::Check (const ICompound* the_compound) {
  if (ok_) return; // TODO throw exception?
  ok_ = true; // TODO check if names are the same?
  if (ok_) {
    type_ = the_compound->kindString()->latin1();
  }
}

void CompoundNode::AddChild (const Ptr& the_child) {
  auto found = children_.find(the_child->name());
  if (found != children_.end())
    return; // FIXME: throw error
  children_.insert(make_pair(the_child->name(), the_child));
}

void CompoundNode::AddChild (ICompound* the_child_compound) {
  stringstream  stream(the_child_compound->name()->latin1());
  string        token;
  Ptr           node = shared_from_this(),
                next;
  while (stream.good()) {
    getline(stream, token, ':');
    next = node->FindChild(token);
    if (!next) {
      next = Ptr(new CompoundNode(token));
      node->AddChild(next);
    }
    node = next;
    getline(stream, token, ':');
  }
  node->Check(the_child_compound);
}

CompoundNode::Ptr CompoundNode::FindChild (const string& the_name) const {
  auto found = children_.find(the_name);
  return found != children_.end() ? found->second : nullptr;
}

void CompoundNode::DumpTree (ostream& out, const string& ident) const {
  string name = name_;
  string type = ok_ ? type_ : "???";
  out << ident << name << " [" << type << "]" << endl;
  for (const auto& child : *this)
    child.second->DumpTree(out, ident+"  ");
}

} // namespace intro
} // namespace op

