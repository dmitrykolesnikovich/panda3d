// Filename: guiButton.h
// Created by:  cary (30Oct00)
// 
////////////////////////////////////////////////////////////////////

#ifndef __GUIBUTTON_H__
#define __GUIBUTTON_H__

#include "guiItem.h"
#include "guiRegion.h"
#include "guiLabel.h"
#include "guiManager.h"

class EXPCL_PANDA GuiButton : public GuiItem {
private:
  GuiLabel* _up;
  GuiLabel* _up_rollover;
  GuiLabel* _down;
  GuiLabel* _down_rollover;
  GuiLabel* _inactive;
  string _up_event, _up_rollover_event, _down_event, _down_rollover_event;
  string _inactive_event;
  GuiRegion* _rgn;

  enum States { NONE, UP, UP_ROLLOVER, DOWN, DOWN_ROLLOVER, INACTIVE,
		INACTIVE_ROLLOVER };
  States _state;

  INLINE GuiButton(void);
  void switch_state(States);
  virtual void recompute_frame(void);
public:
  GuiButton(const string&, GuiLabel*, GuiLabel*);
  GuiButton(const string&, GuiLabel*, GuiLabel*, GuiLabel*);
  GuiButton(const string&, GuiLabel*, GuiLabel*, GuiLabel*, GuiLabel*,
	    GuiLabel*);
  virtual ~GuiButton(void);

  virtual void manage(GuiManager*, EventHandler&);
  virtual void unmanage(void);
  INLINE void enter(void);
  INLINE void exit(void);
  INLINE void up(void);
  INLINE void down(void);
  INLINE void inactive(void);
  INLINE void click(void);

  INLINE bool is_up(void) const;
  INLINE bool is_over(void) const;
  INLINE bool is_active(void) const;

  INLINE void set_up_event(const string&);
  INLINE void set_up_rollover_event(const string&);
  INLINE void set_down_event(const string&);
  INLINE void set_down_rollover_event(const string&);
  INLINE void set_inactive_event(const string&);

  INLINE const string& get_up_event(void) const;
  INLINE const string& get_up_rollover_event(void) const;
  INLINE const string& get_down_event(void) const;
  INLINE const string& get_down_rollover_event(void) const;
  INLINE const string& get_inactive_event(void) const;

  virtual void set_scale(float);
  virtual void set_pos(const LVector3f&);

  virtual void output(ostream&) const;
};

#include "guiButton.I"

#endif /* __GUIBUTTON_H__ */
