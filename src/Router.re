[@bs.val] external document: Js.t({..}) = "document";


let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);
  

  content;
};

[@react.component]
let make = () => {

    let url = ReasonReactRouter.useUrl();
    switch (url.path) {
      | ["atomic"] => ReactDOMRe.render(<Greeting />, makeContainer("Greeting"));
      | ["blinking"] => ReactDOMRe.render(<BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>, makeContainer("Blinking Greeting"),);
      | ["reducer"] => ReactDOMRe.render(<ReducerFromReactJSDocs />, makeContainer("Reducer From ReactJS Docs"),);
      | ["dogs"] => ReactDOMRe.render(  <FetchedDogPictures />, makeContainer("Fetched Dog Pictures"),);
      | ["dog"] => ReactDOMRe.render(<FetchRandomDog />, makeContainer("1 random Dog"));
};

    <div>
        <button onClick={_ => ReasonReactRouter.push("/atomic")}>{React.string("Atomic Greeting")}</button>
        <button onClick={_ => ReasonReactRouter.push("/blinking")}>{React.string("Blinking Greeting")}</button>
        <button onClick={_ => ReasonReactRouter.push("/reducer")}>{React.string("Reducer From ReactJSDocs")}</button>
        <button onClick={_ => ReasonReactRouter.push("/dogs")}>{React.string("Fetched Dog Pictures")}</button>
        <button onClick={_ => ReasonReactRouter.push("/dog")}>{React.string("1 Random Dog")}</button>
    </div>
}